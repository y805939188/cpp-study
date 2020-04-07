import { useMemo } from 'react';
// import debounce from 'lodash/debounce';
export { default as useSetState } from 'react-use/lib/useSetState';
export { default as useMount } from 'react-use/lib/useMount';
export { default as useUpdateEffect } from 'react-use/lib/useUpdateEffect';
export { default as useUnmount } from 'react-use/lib/useUnmount';
// export { default as useDebouncedCallback } from 'use-debounce/lib/useDebouncedCallback';
/*
  use-debounce 内部八成就是这么实现的
  const useDebouncedCallback = (fn, timeout) => (useMemo(() => {
    return debounce(fn, timeout);
  }, []))
*/
// export const useDebouncedCallback = (fn: (...a: any) => any, timeout: number) => (useMemo(() => {
//   return [debounce(fn, timeout)];
// }, []));
