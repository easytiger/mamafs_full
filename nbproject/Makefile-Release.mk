#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/MamaFS.o \
	${OBJECTDIR}/mama_callbacks.o \
	${OBJECTDIR}/MamaRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-D_FILE_OFFSET_BITS=64
CXXFLAGS=-D_FILE_OFFSET_BITS=64

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Release/GNU-Linux-x86/mamafs_full

dist/Release/GNU-Linux-x86/mamafs_full: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/mamafs_full ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/MamaFS.o: MamaFS.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/MamaFS.o MamaFS.cc

${OBJECTDIR}/mama_callbacks.o: mama_callbacks.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/mama_callbacks.o mama_callbacks.cc

${OBJECTDIR}/MamaRunner.o: MamaRunner.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/MamaRunner.o MamaRunner.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/mamafs_full

# Subprojects
.clean-subprojects:
