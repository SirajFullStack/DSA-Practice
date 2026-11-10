# AVL Tree in C++

A simple implementation of a self-balancing **AVL Tree** in C++. After every insertion the tree checks the balance factor of each node and performs the required rotations to keep the tree balanced.

## Features

- Insert integer values into the tree
- Automatic balancing using all four rotation cases (LL, RR, LR, RL)
- Duplicate values are rejected
- Zero and negative values are rejected
- Preorder traversal

## Project Structure

| Component | Description |
|---|---|
| `Node` | Tree node holding `data`, `left` and `right` pointers |
| `AVL` | Class that manages the tree (root, insertion, balancing, traversal) |
| `main()` | Demo that inserts a sample array and prints the preorder traversal |

## How It Works

### Height and Balance Factor

```
Balance Factor (BF) = height(left subtree) - height(right subtree)
```

A node is balanced when BF is `-1`, `0` or `1`. If BF is `>= 2` or `<= -2`, the node is unbalanced and a rotation is applied.

### Rotation Cases

| Case | Condition | Fix | Code used |
|---|---|---|---|
| **LL** | BF >= 2 and left child BF >= 0 | Single right rotation on the node | `LL()` |
| **RR** | BF <= -2 and right child BF <= 0 | Single left rotation on the node | `RR()` |
| **LR** | BF >= 2 and left child BF < 0 | Left rotation on left child, then right rotation on node | `RR()` then `LL()` |
| **RL** | BF <= -2 and right child BF > 0 | Right rotation on right child, then left rotation on node | `LL()` then `RR()` |

> **Naming note:** the function names describe the *case* they fix, not the direction of rotation.
> `LL()` performs a **right rotation** and `RR()` performs a **left rotation**.
>
> Quick trick: *who moves up?* If the right child moves up it is a left rotation. If the left child moves up it is a right rotation.

### Insertion Flow

1. `insert(v)` validates the value (must be greater than 0).
2. The value is inserted using normal BST insertion.
3. `checkAVL()` walks the tree (post-order), computes balance factors and applies rotations where needed.

## Public Methods

| Method | Description |
|---|---|
| `AVL()` | Constructor, creates an empty tree |
| `void insert(int v)` | Inserts a value and rebalances the tree |
| `void Preorder()` | Prints the tree in preorder (Root, Left, Right) |

## Build and Run

Requirements: any C++ compiler (g++, clang++, MSVC, Dev-C++, Code::Blocks).

```bash
g++ avl.cpp -o avl
./avl
```

On Windows:

```bash
g++ avl.cpp -o avl.exe
avl.exe
```

## Example

Input array:

```cpp
int arr[] = {10, 20, 30, 40, 50, 60};
```

Output (preorder):

```
40 20 10 30 50 60
```

Resulting tree:

```
        40
       /  \
     20    50
    /  \     \
  10   30     60
```

### Step by step

| Insert | Action |
|---|---|
| 10, 20 | No rotation |
| 30 | RR case at 10, left rotation, 20 becomes root |
| 40 | No rotation |
| 50 | RR case at 30, left rotation, 40 takes its place |
| 60 | RR case at 20, left rotation, 40 becomes root |

## Input Rules

- Duplicate value: prints `Duplicate value is not allowed.`
- Value `<= 0`: prints `Negative value is not allowed.`

## Limitations

- Deletion is not implemented
- Memory is not freed (no destructor), so nodes are leaked when the program ends
- `checkAVL()` rechecks the whole tree after each insertion, which is simpler but slower than the standard approach of rebalancing only along the insertion path
- `Preorder()` prints a debug line (`Yes baby.`) before the traversal, which you may want to remove

## Possible Improvements

- Add `Inorder()` and `Postorder()` traversals
- Add `deleteNode()` with rebalancing
- Store height inside each node to make balance factor calculation O(1)
- Add a destructor to free memory
- Allow zero as a valid value (change `v<=0` to `v<0`)

## License

Free to use for learning and educational purposes.
