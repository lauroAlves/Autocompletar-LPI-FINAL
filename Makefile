# Makefile para compilar o projeto de autocomplete

# Variáveis
CXX = g++
CXXFLAGS = -I./include
LDFLAGS =
OBJDIR = bin
SRCDIR = src
INCDIR = include

# Arquivos de objeto
OBJS = $(OBJDIR)/main.o $(OBJDIR)/autocompletar.o $(OBJDIR)/termo.o

# Regra principal
all: $(OBJDIR)/autocompletar

$(OBJDIR)/autocompletar: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/autocompletar.h $(INCDIR)/termo.h $(INCDIR)/listaordenada.h
	$(CXX) $(CXXFLAGS) -o $@ -c $(SRCDIR)/main.cpp

$(OBJDIR)/autocompletar.o: $(SRCDIR)/autocompletar.cpp $(INCDIR)/autocompletar.h $(INCDIR)/termo.h $(INCDIR)/listaordenada.h
	$(CXX) $(CXXFLAGS) -o $@ -c $(SRCDIR)/autocompletar.cpp

$(OBJDIR)/termo.o: $(SRCDIR)/termo.cpp $(INCDIR)/termo.h
	$(CXX) $(CXXFLAGS) -o $@ -c $(SRCDIR)/termo.cpp

# Limpar arquivos gerados
clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/autocompletar
