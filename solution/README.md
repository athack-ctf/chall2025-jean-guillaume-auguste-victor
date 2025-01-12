# How to Solve the Challenge?

The way it's intended is that participants should RE the `main` program, and identify a system of linear equations (7 equations).
Each equation involves 7 variables, for the 7 character of the password.

Once the participant identifies the system of equations (as follows), it is easy to solve online, and find the seven variables.

```
# first equation:
print("First", pc[0] + pc[1] + pc[2] + pc[3] + pc[4] + pc[5] + pc[6])

# second equation:
print("Second", pc[0] + pc[1] + pc[2] + pc[3] + pc[4] + pc[5] - pc[6])

# third
print("Third", pc[0] + pc[1] + pc[2] + pc[3] + pc[4] - pc[5] + pc[6])

# fourth
print("Fourth", pc[0] + pc[1] + pc[2] + pc[3] - pc[4] + pc[5] + pc[6])

# fourth
print("Fifth", pc[0] + pc[1] + pc[2] - pc[3] + pc[4] + pc[5] + pc[6])

# fourth
print("Sixth", pc[0] + pc[1] - pc[2] + pc[3] + pc[4] + pc[5] + pc[6])

# fourth
print("Seventh", pc[0] - pc[1] + pc[2] + pc[3] + pc[4] + pc[5] + pc[6])
```

To test, just run the container, input garbage --> should fail. Input `At_u5C!` --> should give the flag


## Potential issue:
- It's a 7 character password; I think participants might bruteforce it? So we need to make sure the app is single-threaded and can't handle concurrent requests; then maybe add a delay between two requests.