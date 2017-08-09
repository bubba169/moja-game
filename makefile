.PHONY : linux mac clean

linux:
	make -f linux.make

mac: 
	make -f mac.make

clean:
	rm -Rf output