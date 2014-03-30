//
// Created by 藤井 陽介 on 2014/03/06.
//


#ifndef __MapManager_H_
#define __MapManager_H_


enum MapDataType {
    NONE        = 0,
    MOVE_DIST   = 1,
    ATTACK_DIST = 2,
    MAP_ITEM    = 3,
    PLAYER      = 4,
    ENEMY       = 5,
    OBSTACLE    = 6,
    MOVE_STEP_DIST = 10, // 移動経路
    SELECTED_DIST  = 11, // 選択位置
};

enum MoveDirectionType {
    MOVE_NONE  = -1,
    MOVE_DOWN  = 0,
    MOVE_LEFT  = 1,
    MOVE_RIGHT = 2,
    MOVE_UP    = 3
};

typedef struct _MapIndex {
    int x;
    int y;
    MoveDirectionType moveDictType;
} MapIndex;

typedef struct _MapItem {
    /** 短形マップ上の区分. */
    MapDataType mapDataType;

    MapIndex mapIndex;

    /** 移動可能距離. */
    int moveDist;
    /** 攻撃可能距離. */
    int attackDist;
} MapItem;

typedef struct _ActorMapItem : public MapItem {
    /** プレイヤーを一意に識別するID. */
    int seqNo;
    /** 移動済みフラグ. */
    bool moveDone;
    /** 攻撃済みフラグ. */
    bool attackDone;
} ActorMapItem;

typedef struct _DropMapItem : public MapItem {
    /** ドロップアイテムを一意に識別するID. */
    int seqNo;
    /** アイテムID */
    int itemId;
} DropMapItem;


class MapManager {

};


#endif //__MapManager_H_
