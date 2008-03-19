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
	${OBJECTDIR}/SubscriptionStore.o \
	${OBJECTDIR}/fsutils.o \
	${OBJECTDIR}/SubscriptionEntity.o \
	${OBJECTDIR}/CLParser.o \
	${OBJECTDIR}/MamaRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26
CXXFLAGS=-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../src/wombat_products_4.0/lib -Wl,-rpath ../../src/wombat_products_4.0/lib -lmama -lmamacpp -lmamda -lmamdabook -lmamdaoptions -lwombatcfgcpp -lwombatmsg -lwombatmsgcpp /usr/lib/libfuse.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Release/GNU-Linux-x86/mamafs_full

dist/Release/GNU-Linux-x86/mamafs_full: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/mamafs_full ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/MamaFS.o: MamaFS.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/MamaFS.o MamaFS.cc

${OBJECTDIR}/mama_callbacks.o: mama_callbacks.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/mama_callbacks.o mama_callbacks.cc

${OBJECTDIR}/SubscriptionStore.o: SubscriptionStore.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/SubscriptionStore.o SubscriptionStore.cc

${OBJECTDIR}/fsutils.o: fsutils.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/fsutils.o fsutils.cc

${OBJECTDIR}/SubscriptionEntity.o: SubscriptionEntity.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/SubscriptionEntity.o SubscriptionEntity.cc

${OBJECTDIR}/CLParser.o: CLParser.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/CLParser.o CLParser.cc

${OBJECTDIR}/MamaRunner.o: MamaRunner.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -Werror -I../../src/wombat_products_4.0/include -o ${OBJECTDIR}/MamaRunner.o MamaRunner.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/mamafs_full

# Subprojects
.clean-subprojects:
