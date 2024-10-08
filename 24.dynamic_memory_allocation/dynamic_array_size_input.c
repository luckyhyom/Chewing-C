#include <stdio.h>

/*
    (1) 왜 배열의 크기를 고정시키도록 만들어진걸까?

        스택:
            1. 스택 메모리 할당은 고정된 크기와 연속적인 메모리 블록에 할당되는 특성 덕분에 매우 빠릅니다. *(또한, 배열이므로 인덱스 사용 가능)
            2. 단순히 스택 포인터를 증가시키는 작업만 수행하므로 오버헤드가 거의 없습니다.
            3. 메모리 예측 가능성, 메모리 예약
        힙: 
            힙 메모리 할당은 동적 관리가 필요하며, *메모리 단편화 문제를 해결하거나 적절한 크기의 블록을 찾아야 하기 때문에 훨씬 복잡합니다.
            또한, 메모리 할당 후에 해당 블록을 관리하기 위한 메타데이터를 저장하고, 해제할 때도 추가 작업이 필요합니다.
            이러한 과정이 힙에서의 메모리 할당을 느리게 만듭니다.


    (2) 동적 메모리 할당과 정적 메모리 할당의 성능 차이
        
        동적 메모리 할당의 오버헤드
        1. 메모리 관리자에 의한 동적 메모리 블록 관리
            1-1. 단편화 처리
            1-2. 적절한 크기의 메모리 블록을 찾기
            1-3. 메모리 할당 후에 해당 블록을 관리하기 위한 메타데이터를 저장하고, 해제할 때도 추가 작업이 필요
        2. 배열과 링크드 리스트의 차이

        외부 단편화: 동적 메모리 할당과 해제가 반복되면서, **메모리 공간 사이에 빈 틈(작은 블록)**들이 발생하는 현상
        내부 단편화: 할당된 메모리 블록이 실제로 필요한 크기보다 커서 사용되지 않는 공간이 발생하는 현상
 */
int main() {
    int arr_size;
    printf("배열의 크기 입력 : \n");
    scanf("%d", &arr_size);

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i;
        printf("%d \n", arr[i]);
    }
    
    return 0;
}