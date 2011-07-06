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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=GNU-Windows
CND_CONF=Release_Win32
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Station.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Explosion.o \
	${OBJECTDIR}/SolarSystem.o \
	${OBJECTDIR}/Ship.o \
	${OBJECTDIR}/ShipCamera.o \
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
LDLIBSOPTIONS=../Skyfire/dist/Release_Win32/GNU-Windows/libskyfire.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ../Skyfire/dist/Release_Win32/GNU-Windows/libskyfire.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -lpthread -lGLU -lSDL -ljpeg -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Station.o: Station.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Station.o Station.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Explosion.o: Explosion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Explosion.o Explosion.cpp

${OBJECTDIR}/SolarSystem.o: SolarSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SolarSystem.o SolarSystem.cpp

${OBJECTDIR}/Ship.o: Ship.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Ship.o Ship.cpp

${OBJECTDIR}/ShipCamera.o: ShipCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShipCamera.o ShipCamera.cpp

${OBJECTDIR}/Galaxy.o: Galaxy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Galaxy.o Galaxy.cpp

# Subprojects
.build-subprojects:
	cd ../Skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Release_Win32

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe

# Subprojects
.clean-subprojects:
	cd ../Skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Release_Win32 clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
