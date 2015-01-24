LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
				  ../../Classes/Controller/InterfaceGame.cpp \
				  ../../Classes/Controller/MapController.cpp \
				  ../../Classes/Controller/MenuController.cpp \
				  ../../Classes/Controller/ReadLevel.cpp \
				  ../../Classes/Controller/SoundController.cpp \
				  ../../Classes/Model/Cell/AngleWall.cpp \
				  ../../Classes/Model/Cell/Cell.cpp \
				  ../../Classes/Model/Cell/CellPortal.cpp \
				  ../../Classes/Model/Cell/EndWall.cpp \
				  ../../Classes/Model/Cell/Flooring.cpp \
				  ../../Classes/Model/Cell/IntersectionWall.cpp \
				  ../../Classes/Model/Cell/TileCell.cpp \
				  ../../Classes/Model/Cell/Wall.cpp \
				  ../../Classes/Model/Characters/Boat.cpp \
				  ../../Classes/Model/Characters/Character.cpp \
				  ../../Classes/Model/Interface/CardCharacter.cpp \
				  ../../Classes/Model/Object/Bed.cpp \
				  ../../Classes/Scene/AbstractScene.cpp \
				  ../../Classes/Scene/GameScene.cpp \
				  ../../Classes/Scene/LogoScene.cpp \
				  ../../Classes/Scene/MenuScene.cpp \
				  ../../Classes/Tools/PPoint.cpp \
				  ../../Classes/Tools/Scroller.cpp \
				  ../../Classes/Tools/Snow.cpp \
				  ../../Classes/TinyXml/tinystr.cpp \
				  ../../Classes/TinyXml/tinyxml.cpp \
				  ../../Classes/TinyXml/tinyxmlerror.cpp \
				  ../../Classes/TinyXml/tinyxmlparser.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
