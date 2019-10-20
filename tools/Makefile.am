libexec_SCRIPTS = mini-gcc.specs
bin_SCRIPTS = mini-gcc
CLEANFILES = $(libexec_SCRIPTS) $(bin_SCRIPTS)
EXTRA_DIST = mini-gcc.in mini-gcc.specs.in

replace = sed -e 's,[@]CC[@],$(CC),g' \
	      -e 's,[@]libdir[@],$(libdir),g' \
	      -e 's,[@]includedir[@],$(includedir),g' \
	      -e 's,[@]libexecdir[@],$(libexecdir),g'

mini-gcc.specs: mini-gcc.specs.in Makefile
	$(replace) < $(srcdir)/$< > $@

mini-gcc: mini-gcc.in Makefile
	$(replace) < $(srcdir)/$< > $@
	chmod +x $@
