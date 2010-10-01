#
# Generated Makefile - do not edit!
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
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Station.o \
	${OBJECTDIR}/main_list.o \
	${OBJECTDIR}/Ship.o \
	${OBJECTDIR}/SolarSystem.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Galaxy.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../skyfire/dist/Debug/GNU-Linux-x86/libskyfire.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/orcid

dist/Debug/GNU-Linux-x86/orcid: ../skyfire/dist/Debug/GNU-Linux-x86/libskyfire.a

dist/Debug/GNU-Linux-x86/orcid: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -lpthread -lGL -lGLU -lSDL -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Station.o: nbproject/Makefile-${CND_CONF}.mk Station.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/Station.o Station.cpp

${OBJECTDIR}/main_list.o: nbproject/Makefile-${CND_CONF}.mk main_list.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_list.o main_list.cpp

${OBJECTDIR}/Ship.o: nbproject/Makefile-${CND_CONF}.mk Ship.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/Ship.o Ship.cpp

${OBJECTDIR}/SolarSystem.o: nbproject/Makefile-${CND_CONF}.mk SolarSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/SolarSystem.o SolarSystem.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Galaxy.o: nbproject/Makefile-${CND_CONF}.mk Galaxy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../skyfire -MMD -MP -MF $@.d -o ${OBJECTDIR}/Galaxy.o Galaxy.cpp

# Subprojects
.build-subprojects:
	cd ../skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/orcid

# Subprojects
.clean-subprojects:
	cd ../skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
