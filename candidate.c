/* candidate.c
 * cyan5   */

#include <stdio.h>
#include <stdlib.h>
#include "c_func.h"

int main(void){

    /* 引数 */
    int call_lst[SIZE*3];
    int call_hist[HIST*3];

    /* 候補リストの作成 */
    int cand_oridin[SIZE*3];
    int idx_cand = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i != j){
                for(int k=0; k<10; k++){
                    if(k != i && k != j){
                        cand_oridin[idx_cand*3  ] = i;
                        cand_oridin[idx_cand*3+1] = j;
                        cand_oridin[idx_cand*3+2] = k;
                        idx_cand++;
                    }
                }
            }
        }
    }

    printf("input num as \"0 1 2\"\n");



    /* ここから下の内容はnumer0n_serchでも使用できるようにする */
    /* 関数内で定義 */
    int idx;
    int flag_zero;
    hash *hash_lst = NULL;
    int idx_lst[HIST];
    int type = NEU;

    for(int depth=0; depth<HIST; depth++){

        /* 数字の入力 */
        printf("question %d > ", depth+1);
        // printf("num 0 1 2 ? > ");
        if(3 != scanf("%d %d %d", &call_hist[depth*3], &call_hist[depth*3+1], &call_hist[depth*3+2])){
            fprintf(stderr, "input error.\n");
        }

        /* typeを更新 すべてのdepthと比較。DIVが出てきたらDIVで確定なのでbreak
         * 最初がtype == DIV (0) のとき更新の必要なし */
        if(type){
            for(int i=0; i<depth; i++){
                type = calc_type(&call_hist[depth*3], &call_hist[i*3], type);
                if(type == DIV){
                    break;
                }
            }
        }

        /* すべての候補について走査 */
        idx = 0;
        for(int i=0; i<SIZE; i++){

            /* 質問候補のハッシュが0(=同じ質問)の排除 */
            flag_zero = 1;
            for(int j=0; j<=depth; j++){
                idx_lst[j] = calc_idx(&cand_oridin[i*3], &call_hist[j*3], type);
                if(idx_lst[j] == 0){
                    flag_zero = 0;
                    break;
                }
            }

            if(flag_zero && hash_search(hash_lst, idx_lst, depth)){
                hash_push(&hash_lst, idx_lst);
                call_lst[idx*3  ] = cand_oridin[i*3  ];
                call_lst[idx*3+1] = cand_oridin[i*3+1];
                call_lst[idx*3+2] = cand_oridin[i*3+2];
                idx++;
            }
        }

        // printf("\n");
        for(int i=0; i<idx; i++){
            printf("%d%d%d ", call_lst[i*3], call_lst[i*3+1], call_lst[i*3+2]);
        }
        hash_clear(&hash_lst);
        printf("\n");
    }

    return 0;
}
