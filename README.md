# CSCI 366 - Systems Programming

This is the base upstream repository for CSCI 366.  It contains homeworks as well as the class project 
information.

## Getting Your Repo Set Up

In CSCI 366, all project work is done individually.  Please follow these instructions

- Create a *private* repository in your own account by
    - Going to <https://github.com/new>
    - Enter the name `csci-366-spring2021-private`
    - Select `Private`
    - **DO NOT ADD A README.MD or .gitignore!**
    - Navigate to the `Settings` -> `Manage Access` section
    - Add `1cg` as a collaborator

Once your repository is initialized, you can pull it down to your local machine.  Instructions can
be found on the home page of your new repository.

Next, you should add the class repository as an upstream git repo:

```bash
$ git remote add upstream https://github.com/msu/csci-366-spring2021.git
$ git pull upstream master
$ git push
```
This will synchronize your private repository with the class repository.

When you want to get an update from the public class repository you can run this command:

```
$ git pull upstream master
```

## Homeworks

Each homework has it's own directory (`/homework_1`, `/homework_2`, etc.).  Please do your work in the homework directory

## Project: BattleBit

You will implement a simplified, networked version of the gaming classic [BattleShip](https://en.wikipedia.org/wiki/Battleship_(game)).

More information can be found in the `/battlebit` directory

