teste-arvore-b: teste-arvore-b.o arvore-b.o arvore-b-remocao.o
	gcc teste-arvore-b.o arvore-b.o arvore-b-remocao.o -o teste-arvore-b
	del *.o

teste-arvore-b.o: teste-arvore-b.c
	gcc -c teste-arvore-b.c

arvore-b.o: arvore-b.c arvore-b.h
	gcc -c arvore-b.c

arvore-b-remocao.o: arvore-b-remocao.c arvore-b-remocao.h
	gcc -c arvore-b-remocao.c