if [ ! -f "include/Mojagame/PreCompiledHeaders.hpp.gch" ]
then
    make linux_headers
fi

make linux

if [ $? -eq "0" ]
then
    rm -R output/assets
    cp -R assets output/assets

    ./output/hello;
fi