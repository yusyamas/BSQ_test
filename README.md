42Tokyo BSQ

Author:
    yusyamas (42Tokyo C Piscine 2022/10 Fail)

git url:
  git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-a33f054e-881d-4ace-ba40-271e880d3c47-4503845-kkengo

試験結果:
  norm errorで0pts
  makefileがrelink
  1行目のruleをyabcとすると
  yが2桁以上になると動かない
  abcが2行目以降と間違っていても動かない
  コマンドライン引数が./bsqのみの場合にmap条件本体でなく、ファイルパスを受け取るように実装してしまっている
  
