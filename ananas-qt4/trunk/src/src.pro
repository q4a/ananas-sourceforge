TEMPLATE = subdirs
SUBDIRS  = sqldrivers
SUBDIRS  += lib plugins
#SUBDIRS  = designer/formdesigner lib plugins
SUBDIRS += designer ananas
#SUBDIRS += designer demo ananas admin webengine test
#SUBDIRS += plugins/mysql
#SUBDIRS += extensions

TRANSLATIONS = \
    ../translations/ananas-en.ts \
    ../translations/ananas-ru.ts 
