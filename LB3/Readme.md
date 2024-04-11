1. Insert 40:
```javascript
     40
```

2. Insert 30:
```javascript
     40
    /
   30
```
   Perform a right rotation on 40:
```javascript
    30
     \
     40
```

3. Insert 20:
```javascript
    30
   / \
  20  40
```
   Perform a right rotation on 30:
```javascript
    30
   / \
  20  40
```

4. Insert 60:
```javascript
    30
   / \
  20  40
        \
         60
```
   Perform a left rotation on 30:
```javascript
      40
     /  \
    30   60
   /
  20
```

5. Insert 50:
```javascript
      40
     /  \
    30   60
   / \
  20  50
```
   Perform a left rotation on 40:
```javascript
      40
     /  \
    30   60
   / \
  20  50
```

6. Insert 80:
```javascript
      40
     /  \
    30   60
   / \    \
  20  50   80
```
   Perform a left rotation on 40:
```javascript
      50
     /  \
    40   60
   / \    \
  30  45   80
 /
20
```

7. Insert 15:
```javascript
      50
     /  \
    40   60
   / \    \
  30  45   80
 / \
20  15
```
   Perform a right rotation on 50:
```javascript
      40
     /  \
    30   50
   / \  / \
  20 35 45 60
 / \
15 25
```

8. Insert 28:
```javascript
      40
     /  \
    30   50
   / \  / \
  20 35 45 60
 / \   \
15 28   48
```
   Perform a left rotation on 30:
```javascript
      40
     /  \
    35   50
   / \  / \
  30  37 45 60
 / \   \
20 28  48
   /
  15
```

9. Insert 25:
```javascript
      40
     /  \
    35   50
   / \  / \
  30  37 45 60
 / \   \
20 28  48
   / \
  15 25
```
   Perform a right rotation on 40:
```javascript
      35
     /  \
    30   40
   / \  / \
  20 28 37 50
 / \   \
15 25  45
        \
        60
```