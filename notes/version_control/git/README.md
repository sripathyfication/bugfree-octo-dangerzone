# The Git Workflow in a nutshell:-
---------------------------------

### Create A Branch
-------------------

Rule #1 on github : anything in the master branch is deployable at every instant. 

So, nothing should go to master unless you've first verified it in pre production. This is why we
create a branch first. It forks off the main/master branch, where you can do your individual
development and tests. 

It is important to give good names to branches, as this announces to everyone what you've pulled a
branch for.

Git is a core concept in git. Everything is based around it. Anything done in a branch doesn't
affect main branch.

### Add Commits
---------------

Adding, removing modifying code is a commit. Github maintains a history of commits. This makes it
easy for other to track progress.

Important to have useful, comprehensible commit message.

Each commit is a unit of change, thereby, if an error is encountered, we can rollback a particular
commit.


### Open A Pull Request
-----------------------
A pull request is you initiating a peer review. In a nutshell. 

At this point, people of interest can look at what your it entails if your branch is merged. There
is also an @mention in the pull request, that allows you to direct the pull request to specific
people.

### Discuss And Review
----------------------

While a pull request initiates a conversation, this is where most of the discussion should happen.
This process should capture all the review comments about your code.

### Deploy
----------

Once you've verified that your branch passes all the unit tests and other tests you have, you can
deploy your branch. This will push your branch into production. If there are any issues, you can
always roll back to the master in production.

### Merge
---------

Once your branch is verified in production, you can merge your changes to the master branch.

After this point, to get a historical run down on your changes, you can go through the pull
request logs as these are searchable.
