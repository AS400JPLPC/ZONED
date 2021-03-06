#définition des cibles particulières
.PHONY: all mrpropre build

# désactivation des règles implicites
.SUFFIXES:
# nom de l'executable :
PROJET = libZONED

OBJLIB = $(PROJET).a

# Addresse   , sources, lib , objets , includes :
SRCDIR = $(CURDIR)/src/
 
BINDIR = $(CURDIR)/lib/

OBJDIR = $(CURDIR)/obj/

INCLUDES = \
-I $(CURDIR)/ \
-I $(SRCDIR) \
-I $(OBJDIR)

# choix du compilateur :
CXX = g++
# options compilations :   
CXXFLAGS=  -fexpensive-optimizations -O2 -Os -Wmain -pedantic-errors -Wfatal-errors -Wall -Wextra -std=c++17   -Wparentheses -fpermissive 


OBJCPP = $(patsubst %.cpp,$(OBJDIR)%.o,$(notdir $(wildcard $(SRCDIR)*.cpp)))


all : $(PROJET)
 
$(PROJET) : $(OBJCPP)
		ar -r -s $(BINDIR)$(OBJLIB)  $^
ifdef TEST
	ar -t $(BINDIR)$(OBJLIB)
endif

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX)  $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 



msg: mrpropre
	@echo "$(PROJET)"
	@echo "$(CURDIR)"
	@echo "$(SRCDIR)"
	@echo "$(OBJDIR)"
	@echo "$(OBJCPP)"

# pour effacer tous les objet et les executables :
mrpropre:
	
	rm -rf $(OBJDIR)*.*  
	rm -rf $(BINDIR)*.*
# affiche la taille de l'objet résultant
build: 

	du -sh $(BINDIR)$(OBJLIB)
