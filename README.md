# C++23 실습 프로젝트 (2026)

VSCode + CMake + MSYS2 GCC 환경에서 C++23 실습을 진행하는 프로젝트입니다.

## 프로젝트 구조

```
2026_cpp_vscode/
├── CMakeLists.txt          # 루트 CMake 설정 (labs/q* 자동 탐지)
├── CMakePresets.json        # CMake 프리셋 (컴파일러, 빌드 타입)
├── .vscode/
│   ├── settings.json        # VSCode + CMake Tools 설정
│   └── launch.json          # 디버그 실행 설정
├── labs/
│   ├── q01/                 # 실습 문제 01
│   │   ├── CMakeLists.txt
│   │   └── main.cpp
│   ├── q02/                 # 실습 문제 02
│   │   ├── CMakeLists.txt
│   │   └── main.cpp
│   ├── q03/                 # 실습 문제 03
│   │   ├── CMakeLists.txt
│   │   └── pointer.cpp
│   └── ...                  # q04, q05, ... 자동 인식
└── build/                   # 빌드 출력 (gitignore)
```

## 사전 준비

### 1. MSYS2 설치

[https://www.msys2.org](https://www.msys2.org) 에서 다운로드 후 설치합니다.

MSYS2 터미널(UCRT64)에서 도구를 설치합니다:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja mingw-w64-ucrt-x86_64-gdb
```

### 2. 환경 변수 PATH 추가 ⚠️ 중요

`C:\msys64\ucrt64\bin`을 시스템 PATH **최상단**에 추가합니다.

> **주의**: 예전에 설치한 MinGW(예: `C:\MinGW\bin`, `C:\mingw64\bin`)가 PATH에 있으면
> 버전 충돌로 컴파일 오류가 발생합니다. 반드시 **ucrt64\bin이 가장 위**에 있어야 합니다.

**설정 방법:**

1. Windows 검색 → `시스템 환경 변수 편집` → `환경 변수(N)...`
2. 시스템 변수 목록에서 `Path` 선택 → `편집`
3. `새로 만들기` → `C:\msys64\ucrt64\bin` 입력
4. `위로 이동` 버튼으로 **목록 최상단**으로 올리기
5. 확인 → 확인 → **VSCode 재시작**

**확인 방법** (cmd 또는 PowerShell):

```cmd
where gcc
```

출력 첫 줄이 `C:\msys64\ucrt64\bin\gcc.exe` 이어야 합니다.

### 3. CMake Configure 오류 시 (도구 미설치)

VSCode를 열었을 때 하단에 CMake 오류가 뜨는 경우, MSYS2 UCRT64 터미널을 열어서 아래 명령어로 도구를 설치합니다.

> **MSYS2 UCRT64 터미널**: 시작 메뉴 → `MSYS2 UCRT64` (MSYS2가 아닌 UCRT64 터미널을 사용해야 합니다)

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc \
          mingw-w64-ucrt-x86_64-toolchain \
          mingw-w64-ucrt-x86_64-cmake \
          mingw-w64-ucrt-x86_64-ninja
```

설치 완료 후 VSCode를 재시작하고 `Ctrl+Shift+P` → `CMake: Configure`를 실행합니다.

### 4. VSCode 확장 설치

- **C/C++** (`ms-vscode.cpptools`)
- **CMake Tools** (`ms-vscode.cmake-tools`)

## 실행 방법

### 타겟 선택 및 실행

1. VSCode 하단 상태바에서 **빌드 타겟**을 클릭하여 실행할 문제(`q01`, `q02`, ...)를 선택
2. **F5** — 디버그 실행 (브레이크포인트 사용 가능)
3. **Ctrl+F5** — 디버그 없이 실행

### 새 실습 문제 추가

1. `labs/` 아래에 `q` 로 시작하는 폴더를 생성 (예: `labs/q04/`)
2. 기존 문제의 `CMakeLists.txt`를 복사 (내용 수정 불필요)
3. `.cpp` 소스 파일 작성
4. CMake 재구성 (Ctrl+Shift+P → `CMake: Configure`)

각 lab의 `CMakeLists.txt`는 폴더 이름을 타겟으로, `*.cpp` 파일을 소스로 자동 사용합니다:

```cmake
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME DIR_NAME)
file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
add_executable(${DIR_NAME} ${SOURCES})
```

## 빌드 설정

| 항목 | 값 |
|---|---|
| C++ 표준 | C++23 |
| 컴파일러 | GCC (MSYS2 UCRT64) |
| 빌드 시스템 | CMake + Ninja |
| 빌드 타입 | Debug (기본), Release |

Release 빌드로 전환하려면 하단 상태바에서 CMake 프리셋을 `release`로 변경합니다.

## 커밋 메시지 형식

```
<type>(<scope>): <요약>

[선택] 본문 — 무엇을, 왜 변경했는지
```

| type | 의미 |
|---|---|
| `feat` | 새 실습 문제 또는 기능 추가 |
| `fix` | 버그/오류 수정 |
| `docs` | README 등 문서 수정 |
| `chore` | 빌드 설정, 도구 설정 변경 |
| `refactor` | 기능 변경 없이 코드 정리 |

**예시:**
```
feat(q04): 포인터와 참조 실습 추가
fix(q02): 출력 누락 수정
docs: PATH 설정 주의사항 및 pacman 설치 명령 추가
chore(cmake): labs/q* 자동 탐지로 변경
```
