# définition des cibles particulières
.PHONY: exec mrprope build  clean

# désactivation des règles implicites
.SUFFIXES:
# nom de l'executable :
PROJET= $(PG)



# Adresse des sources, des objets et des includes :
SRCDIR = $(CURDIR)/src/
OBJDIR = $(CURDIR)/obj/
BINDIR = $(CURDIR)/bin/



INCLUDES = \
-I/home/soleil/ZONED/src \
-I$(SRCDIR)

OBJ = $(OBJDIR)$(PROJET).o  
RESULT= $(BINDIR)$(PROJET)
 
# choix du compilateur :
CXX = g++
# options compilations :
CPPFLAGS=  -Wall -fexpensive-optimizations -O2 -Os -pedantic-errors  -Wextra -std=c++17 -fPIC  -Wparentheses -ftree-coalesce-vars  -fstack-protector

LDFLAGS=   -lpthread -lctemplate  -lX11   

INCLIB=\
/home/soleil/ZONED/lib/libZONED.a 




# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------
# compilation obj :  ex  #@echo "$(OBJCPP)"



# regle edition de liens  
exec: $(OBJ)
	
ifdef PROD	
	$(CXX)  $(OBJ) -o $(RESULT)   $(LDFLAGS) -s $(INCLIB)  
else
	$(CXX)   $(OBJ) -o $(RESULT)   $(LDFLAGS)   -s $(INCLIB) 
endif 
# regle de compilation des sources objet
$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX)  $(CPPFLAGS) $(INCLUDES)  -o $@ -c $< 


# pour effacer tous les objets :
clean: 
	rm -rf  $(OBJDIR)$(PROJET).o

# pour effacer tous les objet et les executables :
mrprope: clean   
	rm -rf $(RESULT)

# efface objet(s) et affiche la taille de l'objet résultant
build: clean
	 du -sh $(RESULT)

