#!/bin/bash

echo "BEGIN examples-initial/typecheck"
for f in ../examples/jpbasic_chkt_*.asl; do
    echo $(basename "$f")
    ./asl "$f" | egrep ^L > tmp.err
    diff tmp.err "${f/asl/err}"
    rm -f tmp.err
done
echo "END   examples-initial/typecheck"

echo ""
echo "BEGIN examples-full/typecheck"
for f in ../examples/jp_chkt_*.asl; do
    echo $(basename $f)
    ./asl $f | egrep ^L > tmp.err
    if ! (diff tmp.err ${f/asl/err}) &>/dev/null; then
    >&2
    (diff tmp.err ${f/asl/err})
    exit 1 
    fi
    rm -f tmp.err
done
echo "END   examples-full/typecheck"

# echo ""
# echo "BEGIN examples-initial/codegen"
# for f in ../examples/jpbasic_genc_*.asl; do
#     echo $(basename $f)
#     ./asl $f | egrep -v '^\(' > tmp.t
#     ../tvm/tvm tmp.t < 
#     if ! (diff tmp.t ${f/asl/t}) &>/dev/null; then
#      >&2
#      (diff tmp.t ${f/asl/t})
#      exit 1 
#     fi
    
#     rm -f tmp.t
# done
# echo "END   examples-initial/codegen"

# echo ""
# echo "BEGIN examples-full/codegen"
# for f in ../examples/jp_genc_*.asl; do
#     echo $(basename "$f")
#     ./asl "$f" > tmp.out
#     if ! (diff tmp.out ${f/asl/out}) &>/dev/null; then
#      >&2
#      (diff tmp.out ${f/asl/out})
#      exit 1 
#      fi
#     rm -f tmp.out
# done
# echo "END   examples-full/codegen"

echo ""
echo "BEGIN examples-initial/execution"
for f in ../examples/jpbasic_genc_*.asl; do
    echo $(basename "$f")
    ./asl "$f" > tmp.t
    ../tvm/tvm tmp.t < "${f/asl/in}" > tmp.out
    #diff tmp.out "${f/asl/out}"
    if ! (diff tmp.out "${f/asl/out}") &>/dev/null; then
    >&2
    diff tmp.out "${f/asl/out}"
    exit 1 
    fi
    rm -f tmp.t tmp.out
done
echo "END   examples-initial/execution"

echo ""
echo "BEGIN examples-full/execution"
for f in ../examples/jp_genc_*.asl; do
    echo $(basename "$f")
    ./asl "$f" > tmp.t
    ../tvm/tvm tmp.t < "${f/asl/in}" > tmp.out
    #diff tmp.out "${f/asl/out}"
    if ! (diff tmp.out "${f/asl/out}") &>/dev/null; then
    >&2
    diff tmp.out "${f/asl/out}"
    exit 1 
    fi
    rm -f tmp.t tmp.out
done
echo "END   examples-full/execution"

echo ""
echo "BEGIN examples-Extra"
for f in ../examples/extra/test_*.asl; do
    echo $(basename "$f")
    ./asl "$f" > tmp.t
    ../tvm/tvm tmp.t < "${f/asl/in}" > tmp.out
    #diff tmp.out "${f/asl/out}"
    if ! (diff tmp.out "${f/asl/out}") &>/dev/null; then
    >&2
    diff tmp.out "${f/asl/out}"
    exit 1 
    fi
    rm -f tmp.t tmp.out
done
echo "END   examples-Extra"
