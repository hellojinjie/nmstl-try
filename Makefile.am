YFLAGS =
AM_CFLAGS = @CFLAGS@ $(MYFLAGS)
AM_CXXFLAGS = @CXXFLAGS@ $(MYFLAGS)

MAIN = echo  

bin_PROGRAMS = $(MAIN)

LDADD_EXTRAS = -ldl  @BOREALISLIB@ 

LDADD =		$(LDADD_EXTRAS)

INCLUDES =  @NMSTLINCLUDE@                   

DEPENDENCIES = 

                 ###########################################

echo_DEPENDENCIES = 

echo_SOURCES = echo.cc

${echo_DEPENDENCIES}: 


             ###########################################


CLEANFILES = ${echo_DEPENDENCIES}

##############################  end Makefile.am  ###############################
