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

### 2. 환경 변수 PATH 추가

`C:\msys64\ucrt64\bin`을 시스템 PATH에 추가합니다.

### 3. VSCode 확장 설치

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
