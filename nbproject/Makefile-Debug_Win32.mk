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
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug_Win32
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
CCFLAGS=-std=gnu++0x
CXXFLAGS=-std=gnu++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Windows/System32 -L../Skyfire/Lib ../Skyfire/dist/Debug_Win32/MinGW-Windows/libskyfire.a ../Skyfire/Lib/pthreadVCE2.dll ../Skyfire/Lib/libturbojpeg.a ../Skyfire/Lib/libjpeg.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ../Skyfire/dist/Debug_Win32/MinGW-Windows/libskyfire.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ../Skyfire/Lib/pthreadVCE2.dll

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ../Skyfire/Lib/libturbojpeg.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ../Skyfire/Lib/libjpeg.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -static-libgcc -static-libstdc++ -lpthread -lopengl32 -lGLU32 -lGdi32 -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Station.o: nbproject/Makefile-${CND_CONF}.mk Station.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Station.o Station.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Explosion.o: nbproject/Makefile-${CND_CONF}.mk Explosion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Explosion.o Explosion.cpp

${OBJECTDIR}/SolarSystem.o: nbproject/Makefile-${CND_CONF}.mk SolarSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SolarSystem.o SolarSystem.cpp

${OBJECTDIR}/Ship.o: nbproject/Makefile-${CND_CONF}.mk Ship.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Ship.o Ship.cpp

${OBJECTDIR}/ShipCamera.o: nbproject/Makefile-${CND_CONF}.mk ShipCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShipCamera.o ShipCamera.cpp

${OBJECTDIR}/Galaxy.o: nbproject/Makefile-${CND_CONF}.mk Galaxy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Skyfire -I../Skyfire/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Galaxy.o Galaxy.cpp

# Subprojects
.build-subprojects:
	cd ../Skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Debug_Win32

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/orcid.exe

# Subprojects
.clean-subprojects:
	cd ../Skyfire && ${MAKE}  -f skyfire-Makefile.mk CONF=Debug_Win32 clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
