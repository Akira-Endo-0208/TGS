#pragma once


class Input
{
public:	// メンバ関数
	//最新のキーボード情報だったものは１フレーム前のキーボード情報として保存
	void SaveoldKey(){
		for (int i = 0; i < 256; i++)
		{
			oldkey[i] = key[i];
		}
	};
private: // メンバ変数
	//ゲームループで使う変数の宣言
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報
};