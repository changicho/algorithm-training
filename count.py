#!/usr/bin/env python3

from pathlib import Path


# 문제 풀이 저장소 루트
ROOT = Path(__file__).resolve().parent

# 문제 폴더가 아닌 디렉터리
EXCLUDE_DIRS = {
    ".git",
    ".github",
    "scripts",
    "templates",
}


def count_problems(root: Path) -> dict[str, int]:
    """
    README.md가 존재하는 디렉터리를 문제 풀이 1개로 계산한다.

    반환값:
        {
            "Baekjoon": 123,
            "Programmers": 45,
            ...
        }
    """
    counts = {}

    for platform_dir in root.iterdir():
        if not platform_dir.is_dir():
            continue

        if platform_dir.name in EXCLUDE_DIRS:
            continue

        count = 0

        for readme in platform_dir.rglob("README.md"):
            # .git 등의 디렉터리 내부는 제외
            if any(part in EXCLUDE_DIRS for part in readme.parts):
                continue

            count += 1

        if count > 0:
            counts[platform_dir.name] = count

    return counts


def main():
    counts = count_problems(ROOT)

    total = sum(counts.values())

    print("================================")
    print("       Algorithm Problem Count")
    print("================================")

    for platform, count in sorted(counts.items()):
        print(f"{platform:<20} {count:>5}")

    print("--------------------------------")
    print(f"{'TOTAL':<20} {total:>5}")
    print("================================")


if __name__ == "__main__":
    main()