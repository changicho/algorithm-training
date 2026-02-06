import os
import shutil

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DOCS_DIR = os.path.join(BASE_DIR, "docs")


# README.md를 docs로 복사 (폴더 구조 유지)
def collect_readmes():
    for root, dirs, files in os.walk(BASE_DIR):
        if "README.md" in files and root != BASE_DIR:
            rel_path = os.path.relpath(root, BASE_DIR)
            target_dir = os.path.join(DOCS_DIR, rel_path)
            os.makedirs(target_dir, exist_ok=True)
            shutil.copy(
                os.path.join(root, "README.md"), os.path.join(target_dir, "README.md")
            )


if __name__ == "__main__":
    collect_readmes()
    print("README.md 파일들을 docs 폴더로 복사 완료!")
