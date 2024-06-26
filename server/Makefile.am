## Process this file with automake to produce Makefile.in

SUBDIRS = advisors generator savegame scripting ruleset

bin_PROGRAMS = freeciv-server

lib_LTLIBRARIES = libfreeciv-srv.la
AM_CPPFLAGS = \
	-I$(top_srcdir)/ai \
	-I$(top_srcdir)/ai/classic \
	-I$(top_srcdir)/common \
	-I$(top_srcdir)/common/aicore \
	-I$(top_srcdir)/common/networking \
	-I$(top_srcdir)/common/scriptcore \
	-I$(top_srcdir)/utility \
	-I$(srcdir)/advisors \
	-I$(srcdir)/generator \
	-I$(srcdir)/ruleset \
	-I$(srcdir)/savegame \
	-I$(srcdir)/scripting \
	-I$(top_srcdir)/dependencies/tinycthread \
	-I$(top_srcdir)/gen_headers/enums \
	$(LUA_CFLAGS) \
	$(FCDB_MYSQL_CFLAGS) $(FCDB_POSTGRES_CFLAGS) $(FCDB_SQLITE3_CFLAGS)

if MINGW
SERVERICON = $(top_builddir)/platforms/windows/icons/servericon.o
endif

exe_sources = \
		srv_entrypoint.c

libfreeciv_srv_la_SOURCES = \
		actiontools.c	\
		actiontools.h	\
		aiiface.c	\
		aiiface.h	\
		animals.c	\
		animals.h	\
		auth.c		\
		auth.h		\
		barbarian.c	\
		barbarian.h	\
		citizenshand.c	\
		citizenshand.h	\
		cityhand.c	\
		cityhand.h	\
		citytools.c	\
		citytools.h	\
		cityturn.c	\
		cityturn.h	\
		commands.c	\
		commands.h	\
		connecthand.c	\
		connecthand.h	\
		console.c	\
		console.h	\
		diplhand.c	\
		diplhand.h	\
		diplomats.c	\
		diplomats.h	\
		edithand.c	\
		edithand.h	\
		fcdb.c		\
		fcdb.h		\
		gamehand.c	\
		gamehand.h	\
		handchat.c	\
		handchat.h	\
		hand_gen.c	\
		hand_gen.h	\
		infrapts.c	\
		maphand.c	\
		maphand.h	\
		meta.c		\
		meta.h		\
		mood.c		\
		mood.h		\
		notify.c	\
		notify.h	\
		plrhand.c	\
		plrhand.h	\
		report.c	\
		report.h	\
		sanitycheck.c	\
		sanitycheck.h	\
		score.c		\
		score.h		\
		sernet.c	\
		sernet.h	\
		setcompat.c	\
		setcompat.h	\
		settings.c	\
		settings.h	\
		spacerace.c	\
		spacerace.h	\
		srv_log.c	\
		srv_log.h	\
		srv_main.c	\
		srv_main.h	\
		srv_signal.c	\
		srv_signal.h	\
		stdinhand.c	\
		stdinhand.h	\
		techtools.h	\
		techtools.c	\
		unithand.c	\
		unithand.h	\
		unittools.c	\
		unittools.h	\
		voting.c	\
		voting.h

# hand_gen.c & hand_gen.h are generated files, but as they are generated
# outside this directory (when building common) there's no point in
# setting them to BUILT_SOURCES.

da_libs =

if AI_MOD_DEFAULT_NEEDED
da_libs += $(top_builddir)/ai/default/libdefaultai.la
endif

if AI_MOD_STATIC_CLASSIC
da_libs += $(top_builddir)/ai/classic/libclassicai.la
endif
if AI_MOD_STATIC_TEX
da_libs += $(top_builddir)/ai/tex/libtexai.la
endif
if AI_MOD_STATIC_STUB
da_libs += $(top_builddir)/ai/stub/libstubai.la
endif

# These files are not generated to builddir, but to srcdir
MAINTAINERCLEANFILES = \
	$(srcdir)/hand_gen.c \
	$(srcdir)/hand_gen.h

srvlibs = \
 $(da_libs) \
 $(top_builddir)/ai/libaicommon.la \
 $(top_builddir)/server/advisors/libadvisors.la \
 $(top_builddir)/server/generator/libgenerator.la \
 $(top_builddir)/server/ruleset/libruleload.la \
 $(top_builddir)/server/savegame/libsavegame.la \
 $(top_builddir)/server/scripting/libscripting_fcdb.la \
 $(top_builddir)/server/scripting/libscripting_server.la

libfreeciv_srv_la_LIBADD = \
 $(srvlibs) $(SRV_LIB_LIBS) \
 $(LUA_LIBS) $(TOLUA_LIBS) $(LUASQL_LIBS)

exe_ldflags =

exe_ldadd = \
 ./libfreeciv-srv.la \
 $(top_builddir)/common/libfreeciv.la \
 $(top_builddir)/dependencies/cvercmp/libcvercmp.la \
 $(INTLLIBS) \
 $(MAPIMG_WAND_LIBS) \
 $(TINYCTHR_LIBS) \
 $(SERVER_LIBS) $(SERVERICON)

freeciv_server_SOURCES = $(exe_sources)
freeciv_server_LDFLAGS = $(exe_ldflags)
freeciv_server_LDADD = $(exe_ldadd)
