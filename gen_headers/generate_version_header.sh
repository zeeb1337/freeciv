#!/bin/sh

VERSION_SCRIPT_SILENT=yes . $(dirname $0)/../fc_version

echo "/* Generated by gen_headers/generate_version_header.sh. */" > $1
echo ""                                             >> $1
echo "#ifndef FC__VERSION_GEN_H"                    >> $1
echo "#define FC__VERSION_GEN_H"                    >> $1
echo ""                                             >> $1
echo "#define MAJOR_VERSION $MAJOR_VERSION"         >> $1
echo "#define MINOR_VERSION $MINOR_VERSION"         >> $1
echo "#define PATCH_VERSION $PATCH_VERSION"         >> $1
if test "x$EMERGENCY_VERSION" != "x" ; then
  echo "#define EMERGENCY_VERSION $EMERGENCY_VERSION" >> $1
fi
echo "#ifndef VERSION_LABEL"                        >> $1
echo "#define VERSION_LABEL \"$VERSION_LABEL\""     >> $1
echo "#endif"                                       >> $1
echo "#ifndef VERSION_STRING"                       >> $1
echo "#define VERSION_STRING \"$VERSION_STRING\""   >> $1
echo "#endif"                                       >> $1
echo ""                                             >> $1
echo "#ifdef FREECIV_DEBUG"                         >> $1
echo "#define NETWORK_CAPSTRING \"${NETWORK_CAPSTRING} debug\"" >> "$1"
echo "#else"                                                    >> "$1"
echo "#define NETWORK_CAPSTRING \"${NETWORK_CAPSTRING}\""       >> "$1"
echo "#endif /* FREECIV_DEBUG */"                               >> "$1"
echo ""                                             >> $1
echo "#ifndef FOLLOWTAG"                            >> $1
echo "#define FOLLOWTAG \"$DEFAULT_FOLLOW_TAG\""    >> $1
echo "#endif"                                       >> $1
echo "#define FREECIV_DISTRIBUTOR \"$FREECIV_DISTRIBUTOR\"" >> $1
echo ""                                             >> $1
echo "#endif /* FC__VERSION_GEN_H */"               >> $1
