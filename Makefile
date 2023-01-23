# Makefile base - Matheus Jandre

COMP = gcc
CFLAGS = -Wall -std=c99

PROGRAM_NAME = forca

TMP = ./tmp

all:
	@$(COMP) $(CFLAGS) main.c -o $(PROGRAM_NAME)
	@echo "O executável foi gerado."
	@echo "Para ajuda, digite: ./$(PROGRAM_NAME) <caminho_para_o_arquivo_contendo_as_palavras>"

# COMANDOS PARA LIMPEZA -=-=-=-=-=-=-=-=--=-=-=-=

temp:
	@rm -rf $(TMP)/*
	@echo "Todos os arquivos temporários foram removidos."

purge:
	@rm $(PROGRAM_NAME)
	@echo "O executável do programa foi removido."
