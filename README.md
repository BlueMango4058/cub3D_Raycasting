# cub3D - Ray-casting

> **C-based Ray-casting Engine focusing on DDA algorithm and Defensive Map Validation**
> 
> Wolfenstein 3D 스타일의 1인칭 렌더링 엔진을 구현한 프로젝트입니다. 단순히 그래픽 라이브러리를 사용하는 수준을 넘어, 시간적 비중(Temporal Weight) 개념으로 이해한 DDA 알고리즘 최적화와 BFS 기반의 방어적 맵 검증 시스템 구축에 집중했습니다.


## Technical Specifications
본 프로젝트는 macOS와 Linux(Ubuntu) 환경에서 지원하도록 설계되었습니다.

* **Language**: C
* **Graphics Library**: miniLibX (X11 & OpenGL)
* **OS Compatibility**: 
    * macOS: OpenGL 및 AppKit 프레임워크 기반 동작
    * Linux: libx11-dev, libxext-dev, zlib1g-dev 설치 필요


## Instructions

# 1. 빌드 (Makefile)
make

# 2. 실행 (.cub 설정 파일 경로 필요)
./cub3D maps/(path/map_name).cub


## Technical Highlights

### 1. Temporal Scale-based Depth Calculation
전통적인 유클리드 거리 방식 대신, 광선의 이동 '시간'을 기준으로 DDA 알고리즘을 재해석하여 구현했습니다.

* **Speed Normalization**: 광선 방향 설정 단계에서 대각선 광선의 벡터 길이를 미리 보정하여, 모든 광선이 카메라 평면에 도달하는 시간을 동기화했습니다.
* **Fisheye Correction**: 이 설계를 통해 누적된 시간(wall_depth)이 별도의 삼각함수 보정 없이도 순수한 수직 깊이를 나타내게 되어 연산 비용을 최적화했습니다.

### 2. BFS-based Map Validation
단순한 재귀형 Floodfill의 스택 오버플로우 위험을 방지하기 위해 큐(Queue) 자료구조를 활용한 BFS를 도입했습니다.

* **Disconnected Map Detection**: 플레이어 위치로부터 연결되지 않은 모든 '섬(Island)' 형태의 잘못된 맵 데이터를 O(N)의 시간 복잡도로 검출하여 완벽한 폐쇄성을 보장합니다.

### 3. Interaction & UX Optimization
* **Sliding Collision**: 벽에 비스듬히 부딪힐 때 멈추지 않고 벽면을 타고 미끄러지는 물리 로직을 구현했습니다.
* **Frame Capping**: gettimeofday를 활용한 프레임 제어로 하드웨어 성능에 관계없이 일정한 이동 속도와 부드러운 화면 갱신을 제공합니다.
* **Key Event State Management**: 키의 눌림(Press)과 뗌(Release) 상태를 플래그 배열로 실시간 기록하여, 여러 키가 동시에 입력되어도 끊김 없는 부드러운 대각선 이동과 회전 조작을 구현했습니다.


## Documentation
이 프로젝트의 수학적 공식 도출 과정, 상세 함수 계층도, 트러블슈팅 사례는 아래 노션 문서에 상세히 기록되어 있습니다.

👉 [cub3D 상세 설계서 확인하기 (Notion)](https://www.notion.so/cub3D-2e1283205b0480feba93d150bf1d527b?source=copy_link)


## Reference & AI Collaboration
* **Logic Reference**: Lode's Raycasting Tutorial
* **AI Assistance**: 
    * Refactoring: 코드의 모듈화 및 유지보수성 향상을 위한 아키텍처 설계 가이드
    * Texture Optimization: 벽 근처 클리핑 이슈 해결 및 안정적인 tex_pos 산출 로직 고도화
    * UX Enhancement: 프레임 캡핑 기술 및 다중 키 입력 동기화 시스템 구축
