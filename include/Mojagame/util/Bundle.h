#pragma once

class Bundleable {
    public:
        virtual ~Bundleable() {};
};

template<typename T>
class Bundled : public Bundleable {
    public:
        Bundled(T val) {_val = val;};
        T get() {return _val;};
    protected:
        T _val;
};

/**
 * Container is a wrapper around std::map that stores pointers to values.
 */

class Bundle {

    public:
        virtual ~Bundle() {
            std::for_each(_data.begin(), _data.end(), [] (std::pair<std::string,Bundleable*> val) {
                delete val.second;
            });
        }
        template<typename T>void set(std::string key, T value) {
            _data[key] = (Bundleable*)(new Bundled<T>(value));
        };
        template<typename T>T get(std::string key) {
            if (!has(key)) {
                printf("Could not find a value for key '%s'\n", key.c_str());
                throw "InvalidKey";
            }

            Bundled<T>* value = dynamic_cast<Bundled<T>*>(_data[key]);
            if (!value) {
                printf("Could not cast to the required type for key '%s'\n", key.c_str());
                throw "InvalidType";
            }

            return value->get();
        };
        bool has(std::string key) {
            return _data.count(key) > 0;
        }
        template<typename T>bool is(std::string key) {
            return has(key) && dynamic_cast<Bundled<T>*>(_data[key]);
        }


    protected:
        std::map<std::string,Bundleable*> _data;

};