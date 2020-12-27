# ProgrammingContest

## AtCoder
AtCoder のコンテストの解答

## LeetCode
LeetCode のコンテストの解答

## book
「プログラミングコンテスト攻略のためのアルゴリズムとデータ構造」


## Commit message prefixes
commitする際は以下のprefixをつけるようにする。
(reference: https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#type)
- chore: Changes to the build process or auxiliary tools and libraries such as documentation generation
- contest: 参加したコンテストの回答を追加
- practice: 過去問や練習問題の回答を追加
- docs: Documentation only changes
- fix: A bug fix
- refactor:  A code change that neither fixes a bug nor adds a feature

上記のprefixがついていない場合に強制的にcommitを弾くようにするには、
プロジェクトルート直下のcommit-msgを.git/hooks/commit-msgに配置する。
```bash
ln -s <project_root>/commit-msg <project_root>/.git/hooks/commit-msg
```
commit-mst内の以下の部分を変更することで、有効なprefix名を変更できる。
```bash
prefixes=("chore:" "contest:" "practice:" "docs:" "fix:" "refactor:")
```

