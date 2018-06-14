all: sprites_8x8.png

clean:
	rm -f sprites_8x8.png

sprites_8x8.png:
	convert -append sprites/*.png sprites_8x8.png
	optipng -o7 -strip all -quiet sprites_8x8.png

test.h:
	for entry in sprites/*;				\
	do						\
		echo "#define $$entry" >> test.h;	\
	done
