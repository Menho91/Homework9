# Homework9

## 📺게임 화면
![image](https://github.com/user-attachments/assets/17e47d0c-5b16-4acf-becf-5649160d17e6)

- 화면 가운데에 남은 기회가 표시됩니다.
- 화면 아래쪽 채팅창에 채팅을 입력할 수 있고, / 로 시작하는 채팅을 치면 기회를 소모하여 숫자를 맞힐 수 있습니다.
- 양 쪽 모두 기회가 모두 소진되면 재시작합니다.

## 🔗게임 로직
### 1️⃣ 로그인
![image](https://github.com/user-attachments/assets/359365d5-39c7-47f6-87f3-a90031f09bd9)

레벨 블루프린트에서 로그인한 컨트롤러를 서버에서 RPC로 각 클라이언트에게 로그인 함수를 실행시키면,

![image](https://github.com/user-attachments/assets/ec733caa-c8a2-4a61-b8cc-d8362de4e89d)

위젯 블루프린트에서 텍스트박스의 디폴트 텍스트를 UserID 로 세팅합니다.
### 2️⃣ 게임 초기화
게임모드 블루프린트에서 BeginPlay에 연결된 GameInitialize 함수는

![image](https://github.com/user-attachments/assets/a392e99a-0837-4c2d-b2ce-5eb4489b4acd)

초기화 작업으로 각 플레이어 컨트롤러의 기회를 초기화하고, GenerateBaseball로 새로 숫자를 생성한 뒤 설정해줍니다.
### 3️⃣ 채팅 처리
![image](https://github.com/user-attachments/assets/e81930ac-def3-43ad-aa00-a80cdd08fc38)

텍스트 박스를 통해 작성한 메시지는 이벤트 디스패처를 통해 컨트롤러 블루프린트로 이동합니다.

![image](https://github.com/user-attachments/assets/0636ce53-ace5-4e3c-88b8-e74f1d75cd16)

이동한 메시지는 맨 앞에 / 가 있는지 확인하고, 있으면 게임 처리를, 없다면 그대로 채팅으로 처리되게 합니다.

![image](https://github.com/user-attachments/assets/5053e3c9-6ad1-4614-a089-85ca95989fcb)

또한 게임으로 처리할 때, 기회가 남아있지 않다면 기회를 모두 소모했다는 메시지를 출력합니다.
### 4️⃣ 게임 처리
![image](https://github.com/user-attachments/assets/b8b88a1d-f254-4d07-aadc-74a2964fea44)

기회가 남아있다면, 메시지에서 / 를 뺀 나머지 부분을 Blueprint Function Library로 만든 PlayBaseballGame 함수에 Input으로 넣고, 게임 모드에서 생성한 숫자와 비교하여 처리합니다.

PlayBaseballGame에서의 결과를 Append로 처리한 뒤, 남은 기회를 하나 삭제한 뒤 출력합니다.
### 5️⃣ 채팅 출력
![image](https://github.com/user-attachments/assets/91ab7244-618b-48a0-a080-6f947b4ce7bb)

각 플레이어 컨트롤러에게 메시지를 출력하고, 출력이 완료되면 메시지를 게임 관련하여 판별하는 GameRule 이벤트로 넘어갑니다.
### 6️⃣ 게임 규칙 적용
![image](https://github.com/user-attachments/assets/4684651d-e734-4551-bd8d-8de51d8e8cde)

만약 3 Strike 가 나왔다면, 모든 플레이어 컨트롤러에 어떤 플레이어가 이겼는지 출력한 뒤, GameInitialize 이벤트를 통해 초기화합니다.

![image](https://github.com/user-attachments/assets/fb8b4463-57f9-4bc2-b52f-d3c27a4d44f3)

아니라면, 비겼는지 판별하는 로직을 통해 현재 플레이어가 비긴 상태인지 확인합니다.

![image](https://github.com/user-attachments/assets/79b4c6ce-a906-4300-b2d4-2478718d37ed)

비긴 것이 맞다면, 모든 플레이어 컨트롤러에 비겼음을 알리고 GameInitialize 이벤트를 통해 초기화합니다.
### 7️⃣ 숫자 생성
![image](https://github.com/user-attachments/assets/7ef920c8-dcd2-4d95-b543-374d860fc1fa)

게임에 사용되는 숫자를 생성하는 로직은 미리 정해둔 길이만큼이 될 때까지 RandRange를 통해 랜덤 숫자를 생성하고, 같은 숫자가 나오지 않게 처리하여 FString 형태로 반환합니다.
### 8️⃣ 게임 규칙 로직
![image](https://github.com/user-attachments/assets/c3bc07db-c70d-4ee0-91f2-d6fa893fb998)

PlayBaseballGame 로직을 살펴보면 IsValidInput 함수를 통해 확인하고, 맞다면 판정을, 아니라면 그냥 아웃 판정을 내립니다.

![image](https://github.com/user-attachments/assets/7535e2ef-bc0a-4b0f-8368-cc26e826b5dc)

길이가 맞는지, 0은 없는지, 같은 숫자는 없는지, 숫자만 입력했는지 확인 후 모두 통과해야 true를 반환합니다.

![image](https://github.com/user-attachments/assets/510a26ca-2d73-4e70-80e0-b14a541c948d)

GameDecision에서는 우선 정답 숫자와 입력된 숫자를 비교하여, Strike가 몇 개고 Ball이 몇 개인지 확인합니다.

![image](https://github.com/user-attachments/assets/104d11ea-a912-45ed-bf94-82d9c331a17b)

다음 Strike, Ball 문자열을 조합해 결과 FString을 만들고, 반환합니다.
