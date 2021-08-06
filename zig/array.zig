const expect = @import("std").testing.expect;

const array = [_]i32{ 1, 2, 3, 4 };

test "check array length" {
    try expect(array.len == 4);
}
