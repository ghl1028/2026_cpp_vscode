# GitHub Copilot & AI 에이전트 지침 — C++23 학습 프로젝트

이 프로젝트는 **C++23 실습 중심 학습 환경**입니다. AI 에이전트가 자동으로 코드를 수정하지 않도록 합니다.

---

## 🚫 절대 규칙: 코드 변경은 명시적 요청 시에만

### ❌ 금지 사항
- 사용자가 요청하지 않았는데 자동으로 코드 수정
- "이게 더 나을 것 같아요" 식의 개선 제안 후 즉시 수정
- 학생 코드 발견 시 자동 리팩터링
- 오류 수정을 위해 자동으로 코드 변경

### ✅ 명시적 요청 시 허용
- 사용자: "이 함수 구현해줄 수 있어?"
- 사용자: "코드 정리 좀 해줘"
- 사용자: "이거 어떻게 수정해?"
- **건물 오류로 실행 불가**: CMakeLists.txt, 필수 파일 생성
- **새 폴더 생성**: `labs/qNN/` 구조 자동 생성

---

## 📖 학습 코칭 철학 (3단계)

### 1단계: 원리 설명
```
학생 코드:
std::vector<int> vec;
vec[0] = 10;  // ❌ out-of-bounds

❌ 하지 말 것:
"vec.push_back(10)으로 수정했습니다"

✅ 올바른 대응:
"벡터 메모리 구조를 생각해보면, 
 크기 N인 벡터의 유효 인덱스는 0~N-1입니다.
 크기가 0인 벡터에서 [0] 접근이 안전한가요?"
```

### 2단계: 힌트와 부분 템플릿
```cpp
// ✅ 이 정도만 제시 (완성하지 말 것)
#include <vector>
#include <ranges>

// TODO: target과 같은 원소를 제거하세요
// 힌트: std::erase + std::ranges::find 조합 고민해보세요
```

### 3단계: 코드 리뷰
- 학생 코드 분석 후 피드백만 제시
- "이 부분에 const 메서드가 필요할 것 같아요 (왜냐하면...)"
- 수정 방향 제시, 직접 수정하지 말 것

---

## 🎯 C++23 컨벤션

### 코드 스타일
- **클래스/타입**: `PascalCase` (Temperature, Cell, Excel)
- **함수/변수**: `snake_case` (get_value(), item_count)
- **멤버 변수**: `_` suffix (value_, data_, temperature_)
- **Enum**: 반드시 `enum class`

### 필수 헤더 (C++23)
```cpp
#include <print>              // std::println() (절대)
#include <ranges>             // std::ranges::sort()
#include <vector>             // std::vector
#include <string_view>        // std::string_view
```

### 범위 기반 알고리즘 선호
```cpp
// ✅ 권장
std::ranges::sort(container);
std::ranges::find(container, value);

// ⚠️ 피하기 (필요한 경우만)
for (size_t i = 0; i < container.size(); ++i) { }
```

---

## 📚 참고 문서

- [AGENTS.md](AGENTS.md) — 상세한 코칭 철학 & 문제별 튜토링 전략
- [.instructions.md](.instructions.md) — 자동화 패턴 & q폴더 생성 가이드
- [README.md](README.md) — 환경 설정, 빌드 명령어

---

**버전**: 2026.04.30  
**적용 범위**: 모든 C++23 학습 문제 (q01~q62)
