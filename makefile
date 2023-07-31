chmall: jucompiler.l jucompiler.y
	flex jucompiler.l
	yacc -d -v jucompiler.y		
	cc -o jucompiler y.tab.c lex.yy.c