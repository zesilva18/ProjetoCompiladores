lex ./jucompiler.l
yacc -d -v expr.y		
cc -o expr y.tab.c lex.yy.c Tree.c
./expr -t < ./testes/aLittleOfEverything.java