# linux bash命令行（icpc专属）说明

## 1. 创建文件

```bash
# 创建文件夹名为a的文件夹
mkdir -p a

# 创建文件名为a的文件
touch a

```

## 2. 编译代码
```bash
# 编译c++文件
g++ -std=c++17 -O2 -Wall a.cpp

# 运行&&读入数据
./a.out [< input.txt] [> output.txt] # 读入input.txt之前他必须已经存在，output不需要

```

# Git 常用指令说明

## 1. 配置

```bash
# 设置全局用户名
git config --global user.name "用户名"

# 设置全局邮箱
git config --global user.email "邮箱"

# 查看所有配置
git config --list

# 设置命令别名，例如用 st 代替 status
git config --global alias.st status
```

## 2. 创建与克隆仓库

```bash
# 初始化本地仓库
git init

# 克隆远程仓库
git clone <仓库地址>

# 克隆指定分支
git clone -b <分支名> <仓库地址>

# 克隆并初始化子模块
git clone --recurse-submodules <仓库地址>
```

## 3. 基本工作流

```bash
# 查看当前状态
git status

# 添加指定文件到暂存区
git add <文件>

# 添加所有变更到暂存区
git add .

# 提交暂存区内容
git commit -m "提交说明"

# 添加已跟踪文件并提交
git commit -am "提交说明"

# 修改最后一次提交
git commit --amend
```

## 4. 查看历史与差异

```bash
# 查看提交历史
git log

# 简洁图形化查看历史
git log --oneline --graph --all

# 查看工作区与暂存区差异
git diff

# 查看暂存区与最后一次提交差异
git diff --staged

# 查看某次提交详情
git show <commit>

# 查看文件每行最后修改
git blame <文件>
```

## 5. 分支操作

```bash
# 查看本地分支
git branch

# 查看所有分支
git branch -a

# 创建分支
git branch <分支名>

# 切换分支
git checkout <分支名>
git switch <分支名>

# 创建并切换分支
git checkout -b <分支名>
git switch -c <分支名>

# 删除已合并分支
git branch -d <分支名>

# 强制删除分支
git branch -D <分支名>

# 合并指定分支到当前分支
git merge <分支名>

# 变基
git rebase <分支名>
```

## 6. 远程仓库

```bash
# 查看远程仓库
git remote -v

# 添加远程仓库
git remote add origin <仓库地址>

# 删除远程仓库
git remote remove origin

# 获取远程更新，不合并
git fetch

# 拉取并合并
git pull

# 拉取并变基
git pull --rebase

# 推送
git push

# 推送并设置上游分支
git push -u origin <分支名>

# 删除远程分支
git push origin --delete <分支名>
```

## 7. 标签

```bash
# 查看标签
git tag

# 创建轻量标签
git tag <标签名>

# 创建附注标签
git tag -a <标签名> -m "标签说明"

# 推送指定标签
git push origin <标签名>

# 推送所有标签
git push origin --tags

# 删除本地标签
git tag -d <标签名>

# 删除远程标签
git push origin --delete <标签名>
```

## 8. 撤销与回退

```bash
# 恢复工作区文件
git restore <文件>

# 取消暂存
git restore --staged <文件>

# 旧写法：取消暂存
git reset HEAD <文件>

# 撤销提交，保留暂存
git reset --soft HEAD~1

# 撤销提交，保留工作区
git reset --mixed HEAD~1

# 撤销提交并丢弃变更，危险
git reset --hard HEAD~1

# 生成反向提交，安全撤销
git revert <commit>

# 旧写法：丢弃工作区修改
git checkout -- <文件>
```

## 9. 暂存工作区

```bash
# 暂存当前修改
git stash

# 带说明暂存
git stash save "说明"

# 查看暂存列表
git stash list

# 恢复并删除最新暂存
git stash pop

# 恢复但不删除
git stash apply

# 删除最新暂存
git stash drop

# 清空所有暂存
git stash clear
```

## 10. 文件操作

```bash
# 删除文件并暂存
git rm <文件>

# 从版本控制移除但保留本地文件
git rm --cached <文件>

# 重命名或移动文件
git mv <旧路径> <新路径>
```

## 11. 忽略文件

`.gitignore` 文件示例：

```gitignore
*.log
node_modules/
.env
dist/
.DS_Store
```

## 12. 子模块

```bash
# 添加子模块
git submodule add <仓库地址> <路径>

# 初始化子模块
git submodule init

# 更新子模块
git submodule update
```

## 13. 其他常用命令

```bash
# 删除未跟踪文件和目录，危险
git clean -fd

# 拣选某次提交
git cherry-pick <commit>

# 查看引用日志，用于恢复误操作
git reflog

# 二分查找问题提交
git bisect start
git bisect good <commit>
git bisect bad <commit>

# 打包归档
git archive --format=zip --output=archive.zip HEAD
```

## 14. 典型流程

### 新项目初始化

```bash
git init
git add .
git commit -m "init"
git branch -M main
git remote add origin <仓库地址>
git push -u origin main
```

### 日常开发

```bash
git pull
git switch -c feature/xxx

# 修改代码

git add .
git commit -m "feat: xxx"
git push -u origin feature/xxx
```

### 合并到主分支

```bash
git switch main
git pull
git merge feature/xxx
git push
```

## 15. 提交信息规范建议

```text
feat: 新功能
fix: 修复缺陷
docs: 文档变更
style: 格式调整
refactor: 重构
test: 测试相关
chore: 构建或工具变更
```

## 16. 危险命令提醒

```bash
# 丢弃未提交修改，谨慎使用
git reset --hard

# 删除未跟踪文件，谨慎使用
git clean -fd

# 强制推送，可能覆盖远程历史，团队协作慎用
git push -f
```
（注：git命令系deepseek整理，若有问题和歧义请指正^_^）