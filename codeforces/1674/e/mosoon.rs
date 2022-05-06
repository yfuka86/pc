// -*- coding:utf-8-unix -*-
// #![feature(map_first_last)]
#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(unused_macros)]
use std::any::Any;
use std::cmp::Ordering::*;
use std::collections::*;
use std::convert::*;
use std::convert::{From, Into};
use std::error::Error;
use std::f64::consts::PI;
use std::fmt::Debug;
use std::fmt::Display;
use std::fs::File;
use std::hash::Hash;
use std::io::prelude::*;
use std::io::*;
use std::iter::Filter;
use std::marker::Copy;
use std::mem::*;
use std::ops::Bound::*;
use std::ops::RangeBounds;
use std::ops::{Add, Mul, Neg, Sub};
use std::process;
use std::slice::from_raw_parts;
use std::str;
use std::vec;

const INF: i64 = 1223372036854775807;
const UINF: usize = INF as usize;
// const FINF: f64 = 122337203685.0;
const LINF: i64 = 2147483647;
const FINF: f64 = LINF as f64;
const INF128: i128 = 1223372036854775807000000000000;
const MOD: i64 = 1000000007;
// const MOD: i64 = 998244353;
const UMOD: usize = MOD as usize;

const MPI: f64 = 3.14159265358979323846264338327950288f64;
// const MOD: i64 = INF;

use std::cmp::*;
use std::collections::*;
use std::io::stdin;
use std::io::stdout;
use std::io::Write;

macro_rules! p {
    ($x:expr) => {
        println!("{}", $x);
    };
}
macro_rules! d {
    ($x:expr) => {
        println!("{:?}", $x);
    };
}

fn main() {
    solve();
}

// use str::Chars;
#[allow(dead_code)]
fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

#[allow(dead_code)]
fn readi() -> (i64) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    iter.next().unwrap().parse::<i64>().unwrap()
}

#[allow(dead_code)]
fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}
#[allow(dead_code)]
fn read_mat<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

#[allow(dead_code)]
fn readii() -> (i64, i64) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
    )
}

fn readff() -> (f64, f64) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<f64>().unwrap(),
        iter.next().unwrap().parse::<f64>().unwrap(),
    )
}

#[allow(dead_code)]
fn readiii() -> (i64, i64, i64) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
    )
}
#[allow(dead_code)]
fn readuu() -> (usize, usize) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
    )
}

fn readcc() -> (char, char) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<char>().unwrap(),
        iter.next().unwrap().parse::<char>().unwrap(),
    )
}

fn readuuu() -> (usize, usize, usize) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
    )
}
#[allow(dead_code)]
fn readiiii() -> (i64, i64, i64, i64) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
        iter.next().unwrap().parse::<i64>().unwrap(),
    )
}

#[allow(dead_code)]
fn readuuuu() -> (usize, usize, usize, usize) {
    let mut str = String::new();
    let _ = stdin().read_line(&mut str).unwrap();
    let mut iter = str.split_whitespace();
    (
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
        iter.next().unwrap().parse::<usize>().unwrap(),
    )
}

pub struct SEG<M: Monoid> {
    n: usize,
    buf: Vec<M::T>,
}

impl<M: Monoid> SEG<M> {
    #[allow(dead_code)]
    pub fn new(n: usize) -> SEG<M> {
        SEG {
            n,
            buf: vec![M::id(); 2 * n],
        }
    }

    #[allow(dead_code)]
    pub fn update(&mut self, k: usize, a: M::T) {
        let mut k = k + self.n;
        self.buf[k] = a;

        while k > 0 {
            k >>= 1;
            self.buf[k] = M::op(&self.buf[k << 1], &self.buf[(k << 1) | 1]);
        }
    }

    #[allow(dead_code)]
    pub fn add(&mut self, k: usize, a: &M::T) {
        let mut k = k + self.n;
        self.buf[k] = M::op(&self.buf[k], a);

        while k > 0 {
            k >>= 1;
            self.buf[k] = M::op(&self.buf[k << 1], &self.buf[(k << 1) | 1]);
        }
    }

    #[allow(dead_code)]
    pub fn get(&self, i: usize) -> M::T {
        self.query(i, i + 1)
    }

    #[allow(dead_code)]
    pub fn query_range<R: std::ops::RangeBounds<usize>>(&self, range: R) -> M::T {
        let l = match range.start_bound() {
            std::ops::Bound::Excluded(&x) => {
                assert!(x > 0);
                x - 1
            }
            std::ops::Bound::Included(&x) => x,
            std::ops::Bound::Unbounded => 0,
        };
        let r = match range.end_bound() {
            std::ops::Bound::Excluded(&x) => x,
            std::ops::Bound::Included(&x) => (x + 1),
            std::ops::Bound::Unbounded => self.n,
        };

        self.query(l, r)
    }

    #[allow(dead_code)]
    pub fn query(&self, l: usize, r: usize) -> M::T {
        let mut vl = M::id();
        let mut vr = M::id();

        let mut l = l + self.n;
        let mut r = r + self.n;

        while l < r {
            if l & 1 == 1 {
                vl = M::op(&vl, &self.buf[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                vr = M::op(&self.buf[r], &vr);
            }

            l >>= 1;
            r >>= 1;
        }
        M::op(&vl, &vr)
    }
}
pub trait Monoid {
    type T: Clone;
    fn id() -> Self::T;
    fn op(a: &Self::T, b: &Self::T) -> Self::T;
}

pub enum MON {}
impl Monoid for MON {
    type T = u64;
    fn id() -> Self::T {
        0
    }
    fn op(a: &Self::T, b: &Self::T) -> Self::T {
        *a + *b
    }
}
fn solve() {
    let n: usize = read();
    let mut vec: Vec<usize> = read_vec();
    let mut res = UINF;
    for i in 1..n {
        let mut x = max(vec[i], vec[i - 1]);
        let mut y = min(vec[i], vec[i - 1]);
        let abs = x - y;
        if x >= y * 2 {
            res = min((x + 1) / 2, res);
            // dbg!(res);
            continue;
        }
        let mut r = 0;
        r += abs;
        x -= abs * 2;
        y -= abs;
        let mi = min(x, y);
        r += mi / 3 * 2;
        x -= mi / 3 * 3;
        y -= mi / 3 * 3;
        if x == 0 && y == 0 {
            r += 0;
        } else if x + y < 3 {
            r += 1;
        } else {
            r += 2;
        }

        res = min(res, r);
    }
    let mut dat = vec![];
    for i in 0..n {
        let r = ((vec[i]) + 1) / 2;
        dat.push(r);
    }
    dat.sort();
    res = min(res, dat[0] + dat[1]);

    for i in 2..n {
        let r = max(vec[i - 2], vec[i]);
        res = min(res, r);

        let mut r = (vec[i]) / 2 + vec[i - 2] / 2;
        r += max(vec[i - 1] % 2, vec[i - 2] % 2);
        res = min(res, r);
    }
    p!(res);
    return;
}
