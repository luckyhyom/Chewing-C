#include <stdio.h>
#include <stdlib.h>

/*
    게임 인원수 변경하기
*/
int main()
{
    int *players;
    int player_count = 1;
    int player_max_count = 2;
    printf("플레이어 수를 입력해주세요 : \n");
    scanf("%d", &player_max_count);

    players = (int*)malloc(player_max_count * sizeof(int));
    players[0] = 1;

    while (1)
    {
        printf("현재 플레이어 (최대 인원 수 %d 명) : \n", player_max_count);
        for (int i = 0; i < player_max_count; i++)
        {
            if(players[i] == 0) continue;
            printf("-- %d번 플레이어 (id: %d) \n", i+1, players[i]);
        }
        

        int menu;
        printf("메뉴를 선택해주세요 : \n");
        printf("1. 게임 시작 \n");
        printf("2. 유저 초대 \n");
        printf("3. 유저 강퇴 \n");
        printf("4. 플레이어 수 변경 \n");
        printf("5. 방 나가기 \n");
        scanf("%d", &menu);

        if(menu == 1){
            printf("게임 시작! \n");
            printf("게임 끝! \n");
        }
        else if(menu == 2){
            if(player_count >= player_max_count) {
                printf("최대 인원수를 초과합니다. 최대 인원수를 수정해주세요. \n");
                continue;
            }
            int user_id = 0;
            printf("초대 유저 ID 입력: \n");
            scanf("%d", &user_id);
            for (int i = 0; i < player_max_count; i++)
            {
                if(players[i] == 0) {
                    players[i] = user_id;
                    printf("%d 님이 입장하셨습니다. (번호: %d) \n", players[i], i + 1);
                    player_count++;
                    break;
                }
            }
        }
        else if(menu == 3){
            if(player_count == 1) {
                printf("현재 참여중인 플레이어가 없습니다. \n");
                continue;
            }
            int user_id = 0;
            printf("강퇴할 유저 ID 입력: \n");
            scanf("%d", &user_id);
            int is_removed = 0;
            for (int i = 0; i < player_max_count; i++)
            {
                if(players[i] == user_id) {
                    printf("%d 님이 강퇴되었습니다. \n", players[i]);
                    players[i] = 0;
                    player_count--;
                    is_removed = 1;
                }
            }
            if(!is_removed) {
                printf("id가 %d인 유저가 존재하지 않습니다. \n", user_id);
                continue;
            }
        }
        else if(menu == 4){
            int input = player_count;
            printf("최대 인원 수를 입력해주세요. (현재 최대 인원 수: %d)\n", player_max_count);
            scanf("%d", &input);
            if(input < player_count) {
                printf("현재 인원보다 적게 설정할 수 없습니다. \n최대 인원 수를 입력해주세요. (현재 최대 인원 수: %d)\n", player_max_count);
            } else {
                player_max_count = input;
                players = (int*)realloc(players, player_max_count * sizeof(int));
                printf("최대 인원 수가 %d명으로 변경되었습니다. \n", player_max_count);
            }
        }
        else if(menu == 5){
            printf("게임 종료. \n");
            break;
        }
    }
    
    free(players);
    return 0;
}
