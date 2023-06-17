#ifndef CFUNC
#define CFUNC

#define USENUM 10      /* 使用する記号の数             */
#define SIZE 720       /* USENUM*(USENUM-1)*(USENUM-2) */
#define HIST 10

enum type{
    DV,     /* 全てを区別する。notを返す */
    NU,     /* 全て区別しない            */
    LM,     /* LとMは区別しない          */
    LR,     /* LとRは区別しない          */
    MR      /* MとRは区別しない          */
};

typedef struct hash{
    int data[SIZE];
    struct hash *next;
}hash;
/* HIST個のハッシュ値をリストとして保存しておく
 * リストは全て等しい場合のみ、同一の質問候補として扱われる
 * */

int calc_idx(int cand[3], int call_hist[3], int type);
/* 質問履歴から、次の質問候補をハッシュ値で返す
 * 012→013  hash:1  012→014  hash:2  ...  012→345  hash:34 */

int calc_type(int call[3], int call_hist[3], int type);
/* 受け取った質問と質問履歴から、タイプを更新する。
   012→013 : type 0→1  
 * typeを受け取り、値を更新する */

int hash_search(hash *ptr, int data[HIST], int depth);
/* ハッシュ値配列 data[HIST] が 単方向リストhashに含まれているか検索
 * 含まれている場合:0  含まれていない場合:1 */

void hash_push(hash **ptr, int data[HIST]);
// void hash_push(hash **ptr, int data[HIST], int type);
/* 単方向リストhashにデータをプッシュ */

void hash_pop(int *type_stb, int type_tmp);
/* 現在のタイプと新しいタイプからタイプを決定 */

void hash_clear(hash **ptr);
/* 単方向リストhashを空にする */

#endif