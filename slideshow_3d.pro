# ******************************************************************************
#  slideshow_3d.pro                                             Tao project
# ******************************************************************************
# File Description:
# Qt build file for the SlideShow3D module
#
# Shows a collection of pictures on a rotating 3D sphere.
#
# ******************************************************************************
# This software is property of Taodyne SAS - Confidential
# Ce logiciel est la propriété de Taodyne SAS - Confidentiel
# (C) 2011 Jerome Forissier <jerome@taodyne.com>
# (C) 2011 Christophe de Dinechin <christophe@taodyne.com>
# (C) 2011 Taodyne SAS
# ******************************************************************************

MODINSTDIR = slideshow_3d

include(../modules.pri)

OTHER_FILES = slideshow_3d.xl slideshow_3d2.xl

CRYPT_XL_SOURCES = slideshow_3d2.xl
include(../crypt_xl.pri)

# icon from http://www.iconfinder.com/icondetails/18336/32/folder_image_photo_icon
INSTALLS    += thismod_icon
INSTALLS    -= thismod_bin

QMAKE_SUBSTITUTES = doc/Doxyfile.in
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
include(../modules_doc.pri)
