rm -rf static_lib static_inc

hg clone https://bitbucket.org/sinbad/ogre
res=$?
if [ res == 0 ]
then
    echo "Error: hg not found: install mercurial"
    exit
fi

hg --cwd ogre pull && hg --cwd ogre update v1-9
hg clone https://bitbucket.org/cabalistic/ogredeps

mkdir static_lib && mkdir static_inc
mkdir ogredeps/build

cd ogredeps/build
cmake -DOGRE_CONFIG_THREADS=2 ..
make -j9
make install
cd ../..

mkdir ogre/build

cp -R ogredeps/build/ogredeps/include/* static_inc
cp -R ogredeps/build/ogredeps/lib/* static_lib
cp -R ogredeps/build/ogredeps ogre/build

rm -rf ogredeps

cd ogre/build
cmake -DOGRE_CONFIG_THREADS=2 -DOGRE_DEPENDENCIES_DIR=ogredeps/ ..
make -j9

cd ../..
cp ogre/build/lib/libOgre*                      static_lib
cp ogre/build/lib/RenderSystem_*		static_lib
cp ogre/build/include/OgreBuildSettings.h	static_inc
cp -R ogre/OgreMain/include/*			static_inc

rm -rf ogre

tar -xf .tmpcegui/cegui.tar.bz2
mkdir cegui-0.8.7/build
cp .tmpcegui/inc/* cegui-0.8.7/cegui/include/CEGUI/RendererModules/Ogre/
cp .tmpcegui/src/* cegui-0.8.7/cegui/src/RendererModules/Ogre/
cd cegui-0.8.7/build
echo 'include("../.tmpcegui/cegui.cmake")' > tmp
cat ../CMakeLists.txt >> tmp
mv tmp ../CMakeLists.txt
cmake ..
make CEGUIOgreRenderer-0 -j9
make CEGUIExpatParser
make CEGUICoreWindowRendererSet
cp lib/* ../../static_lib/
cp -R cegui/include/CEGUI ../../static_inc
cd ../..
rm -rf cegui-0.8.7
