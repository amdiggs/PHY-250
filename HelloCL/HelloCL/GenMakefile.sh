#!/bin/bash

CXXFLAGS="-g -Wall"



COMPS=$(ls /usr/bin/*++)
for pth in $COMPS
do
	cmp=$(awk -F/ '{print $NF}' <<< $pth)
	if [[ "$cmp" == "g++" ]]
		then CXX="g++"
		break
	elif [[ "$cmp" == "clang++" ]]
		then CXX="clang++"
		break
	else
		echo ""
	fi
done

echo $CXX

USROS=$(echo $OSTYPE)
echo $USROS | grep "darwin"

if [[ $USROS =~ "darwin" ]]
then
	echo "APPLE"
	LIBS="-framework OpenCL"
elif [[ $USROS =~ "linux" ]]
then
	echo "Linux"
	LIBS="-lOpenCL"
else
	echo "Windows"
	LIBS="-lOpenCL"
fi



cat > Makefile << EOF
HelloCL: main.cpp
	$CXX $CXXFLAGS -o HelloCL main.cpp $LIBS
EOF



