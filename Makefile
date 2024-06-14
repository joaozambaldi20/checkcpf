build:
	cc main.c validator.c reporter.c errors.c -o cpfcheck

clean:
	rm a.out -f

