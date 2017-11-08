TIME=`date +%s`
COMPONENTS=/tmp/temporary-0918

E3DE=$COMPONENTS/libtomcrypt.a
F90C=$COMPONENTS/libtfm.a
F03C=$COMPONENTS/libc.a
B502=$COMPONENTS/libgcc.a

tcc -c elaw.c -o /tmp/$TIME.o &&
tcc -o /tmp/$TIME /tmp/$TIME.o $E3DE $F90C $F03C $B502 &&
# tcc -o /tmp/$TIME /tmp/$TIME.o $E3DE $F90C &&
/tmp/$TIME $1
