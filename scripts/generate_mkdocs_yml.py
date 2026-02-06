import os
import yaml

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DOCS_DIR = os.path.join(BASE_DIR, "docs")
MKDOCS_YML = os.path.join(BASE_DIR, "mkdocs.yml")


site_name = "Algorithm Training Blog"
site_url = "https://changicho.github.io/algorithm-training/"
use_directory_urls = True
nav = []

# docs 폴더 내 README.md를 네비게이션으로 추가
for root, dirs, files in os.walk(DOCS_DIR):
    if "README.md" in files:
        rel_path = os.path.relpath(root, DOCS_DIR)
        if rel_path == ".":
            nav.append({"Home": "index.md"})
        else:
            # 폴더 구조를 '/'로 분리해서 네비게이션 계층화
            parts = rel_path.split(os.sep)
            entry = nav
            for part in parts[:-1]:
                found = next(
                    (item for item in entry if isinstance(item, dict) and part in item),
                    None,
                )
                if not found:
                    new = {part: []}
                    entry.append(new)
                    entry = new[part]
                else:
                    entry = found[part]
            entry.append({parts[-1]: f"{rel_path}/README.md"})


mkdocs_dict = {
    "site_name": site_name,
    "site_url": site_url,
    "use_directory_urls": use_directory_urls,
    "nav": nav,
}

with open(MKDOCS_YML, "w", encoding="utf-8") as f:
    yaml.dump(mkdocs_dict, f, allow_unicode=True, sort_keys=False)

print("mkdocs.yml 파일 생성 완료!")
