# Diretório dos outros aqruivos-fonte
FONTES := ../fontes

# Compilador
CC := gcc
CFLAGS := -Wall -Wextra -I$(FONTES)

# Binários
BINS := lista.out \
		listac.out \
		listad.out

# Regras
.PHONY: tudo limpar

tudo : $(BINS)

# lista encadeada simples
lista.out : main_lista.c $(FONTES)/lista.c $(FONTES)/lista.h
	$(CC) $(CFLAGS) main_lista.c $(FONTES)/lista.c -o $@

# lista encadeada com cabeça
listac.out : main_listac.c $(FONTES)/listac.c $(FONTES)/listac.h
	$(CC) $(CFLAGS) main_listac.c $(FONTES)/listac.c -o $@

# lista duplamente encadeada
listad.out : main_listad.c $(FONTES)/listad.c $(FONTES)/listad.h
	$(CC) $(CFLAGS) main_listad.c $(FONTES)/listad.c -o $@

limpar :
	rm -f $(BINS)