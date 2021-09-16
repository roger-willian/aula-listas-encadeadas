# Diretório dos outros aqruivos-fonte
FONTES := ../fontes

# Compilador
CC := gcc
CFLAGS := -Wall -Wextra -I$(FONTES)

# Binários
BINS := p1.out \
		p2.out \
		p3.out

# Regras
.PHONY: tudo limpar

tudo : $(BINS)

# problema 1
p1.out : p1.c $(FONTES)/listac.c $(FONTES)/listac.h
	$(CC) $(CFLAGS) p1.c $(FONTES)/listac.c -o $@

# problema 2
p2.out : p2.c $(FONTES)/listac.c $(FONTES)/listac.h
	$(CC) $(CFLAGS) p2.c $(FONTES)/listac.c -o $@

# problema 3
p3.out : p3.c $(FONTES)/listad.c $(FONTES)/listad.h
	$(CC) $(CFLAGS) p3.c $(FONTES)/listad.c -o $@

limpar :
	rm -f $(BINS)