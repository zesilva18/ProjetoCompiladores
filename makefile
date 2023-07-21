chmall: jucompiler.l expr.y Tree.c Tree.h
	flex jucompiler.l
	yacc -d -v expr.y		
	cc -o expr y.tab.c lex.yy.c Tree.c