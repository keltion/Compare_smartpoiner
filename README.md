# shared_ptr과 scoped_refptr의 비교
chromium에는 scoped_refptr이라는 스마트 포인터가 존재합니다.
  
## std::shared_ptr과 scoped_refptr의 공통점
shared ownership을 제공한다는 점에서 std::shared_ptr와 std::scoped_refptr은 공통점을 갖습니다. 또한 두 스마트포인터 모두 raw pointer를 저장하기 위해 힙 영역에 메모리를 할당받습니다.
  
## std::shared_ptr과 scoped_refptr의 차이점
std::shared_ptr은 참조 카운팅을 수행하는 control block에 대한 포인터를 추가로 갖습니다. 반면 scoped_refptr은 상속을 이용하여 참조카운팅을 진행합니다.
따라서 std::shared_ptr은 scoped_refptr에 비해 malloc() 호출을 1회 더 하게됩니다.
  
## 성능비교
결국 scoped_refptr은 malloc의 호출을 1회로 줄여 성능을 개선한 스마트포인터입니다. 이 프로젝트에서는 std::shared_ptr을 모방한 keliton::shared_ptr과
크로미움의 scoped_refptr을 모방한 keltion::scoped_refptr의 성능을 비교합니다.
  
## 결과
<img width="50%" src="https://user-images.githubusercontent.com/76467273/162622655-ee3b4245-adb3-442d-ac9e-0263ff927ee9.png"/>
